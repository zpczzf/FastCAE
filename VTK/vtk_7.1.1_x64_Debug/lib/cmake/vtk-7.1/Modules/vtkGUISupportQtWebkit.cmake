set(vtkGUISupportQtWebkit_LOADED 1)
set(vtkGUISupportQtWebkit_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkFiltersExtraction;vtkFiltersGeneral;vtkFiltersSources;vtkInfovisCore;vtkViewsCore;vtkViewsQt")
set(vtkGUISupportQtWebkit_LIBRARIES "vtkGUISupportQtWebkit")
set(vtkGUISupportQtWebkit_INCLUDE_DIRS "${VTK_INSTALL_PREFIX}/include/vtk-7.1")
set(vtkGUISupportQtWebkit_LIBRARY_DIRS "")
set(vtkGUISupportQtWebkit_RUNTIME_LIBRARY_DIRS "${VTK_INSTALL_PREFIX}/bin")
set(vtkGUISupportQtWebkit_WRAP_HIERARCHY_FILE "${CMAKE_CURRENT_LIST_DIR}/vtkGUISupportQtWebkitHierarchy.txt")
set(vtkGUISupportQtWebkit_KIT "")
set(vtkGUISupportQtWebkit_EXCLUDE_FROM_WRAPPING 1)

if(NOT Qt5_DIR)
  set(Qt5_DIR "D:/Qt/Qt5.4.2_x64/5.4/msvc2013_64_opengl/lib/cmake/Qt5")
endif()
find_package(Qt5 REQUIRED QUIET COMPONENTS WebKitWidgets)
