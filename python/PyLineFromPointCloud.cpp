#include <pybind11/pybind11.h>
// #include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include <stdio.h>
#include <fstream>

#include <LineDetection3D.h>
#include <nanoflann.hpp>
#include <utils.h>
#include <Timer.h>

using namespace cv;
using namespace std;
using namespace nanoflann;

class Foo
{
public:
	void Hello() { ; }
};

PYBIND11_MODULE(PyLineFromPointCloud, m)
{
	pybind11::class_<LineDetection3D>(m, "LineDetection3D")
		.def(pybind11::init<>())
		.def("run",
			 [](LineDetection3D &self,
				const std::vector<double> &pointData, int k = 20)
			 {
				 PointCloud<double> cloud;
				 const size_t piont_size = pointData.size() / 3;
				 cloud.pts.reserve(piont_size);
				 for (int i = 0; i < piont_size; i++)
				 {
					 cloud.pts.push_back(PointCloud<double>::PtData(pointData[3 * i], pointData[3 * i + 1], pointData[3 * i + 2]));
				 }

				 std::vector<PLANE> planes;
				 std::vector<std::vector<cv::Point3d>> lines;
				 std::vector<double> ts;
				 self.run(cloud, k, planes, lines, ts);
				 std::vector<std::vector<double>> lines_data;
				 for (auto &line : lines)
				 {
					 std::vector<double> line_data;
					 for (auto &p : line)
					 {
						 line_data.push_back(p.x);
						 line_data.push_back(p.y);
						 line_data.push_back(p.z);
					 }

					 lines_data.push_back(line_data);
				 }
				 return std::make_tuple(lines_data, ts);
			 })
		.def_readwrite("k", &LineDetection3D::k);
}