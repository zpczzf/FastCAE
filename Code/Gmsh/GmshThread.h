#ifndef _GMSHTHREAD_H_
#define _GMSHTHREAD_H_

#include <QThread>
#include <QList>
#include <QMultiHash>
#include <QString>
#include <QProcess>
#include "DataProperty/DataBase.h"
#include <QTextStream>
#include <QTime>

class TopoDS_Compound;

namespace GUI
{
	class MainWindow;
}

namespace MainWidget
{
	class PreWindow;
}

namespace ModuleBase
{
	class ProcessBar;
}

namespace Py
{
	class PythonAagent;
}

namespace Gmsh
{
	class GmshModule;

	class GMshPara
	{
	public:
		int _dim{ -1 };
		QMultiHash<int, int> _solidHash{};
		QMultiHash<int, int> _surfaceHash{};
		QString _elementType{};
		int _elementOrder{ -1 };
		int _method{ -1 };
		double _sizeFactor{ 0.0 };
		double _minSize{ 0.0 };
		double _maxSize{ 0.0 };
		bool _geoclean{ false };
		int _smoothIteration{ 0 };
		bool _isGridCoplanar{ false };
		QString _sizeAtPoints{};
		QString _sizeFields{};
	//	QString _physicals{};
		bool _selectall{ false };
		bool _selectvisible{ false };

	};

	class GmshThread : public DataProperty::DataBase
	{
		Q_OBJECT
	public:
		GmshThread(GUI::MainWindow* mw, MainWidget::PreWindow* pre, GmshModule* mod, int dim);
		~GmshThread();

		//设置参数
		void setPara(GMshPara*  para);

		//追加实体
		void appendSolid(int id, int index);
		void setSolid(QMultiHash<int, int> s);
		//追加曲面
		void appendSurface(int geo, int face);
		void setSurface(QMultiHash<int, int> s);
		//设置单元类型
		void setElementType(QString t);
		//设置单元阶次
		void setElementOrder(int order);
		//设置网格剖分方法
		void setMethod(int m);
		//设置尺寸因子
		void setSizeFactor(double f);
		//设置最小尺寸
		void setMinSize(double min);
		//设置最大尺寸
		void setMaxSize(double max);
		//设置是否进行几何清理
		void isCleanGeo(bool c);
		//设置光滑迭代次数
		void setSmoothIteration(int it);
		//设计是否网格功面
		void setGridCoplanar(bool gc);
		//设置点网格密度
		void setSizeAtPoint(QString ps);
		//设置区域网格密度
		void setSizeFields(QString fs);
		//设置物理分组
		//void setPhysicals(QString ps);

		void setSelectedAll(bool al);
		void setSelectedVisible(bool sv);

		void run();
		void stop();

	signals:
		void threadFinished(GmshThread* t);
		void sendMessage(QString);

	private slots:
	   void processFinished(int, QProcess::ExitStatus);
		void readProcessOutput();

	private:
		void mergeGeometry();
		void initGmshEnvoirment();
		void submitParaToGmsh();
		void generate();
		void readMesh();
		void appendScript(QString path);
		void generalSetting(QTextStream* out);
		void gridCoplanar(QTextStream* out);
		void sizeAtPoints(QTextStream* out);
		void sizeFields(QTextStream* out);
		void boxFieldScript(QTextStream* out, QStringList list, int& index);
		void ballFieldScript(QTextStream* out, QStringList list, int& index);
		void cylinderFieldScript(QTextStream* out, QStringList list, int& index);
	//	void physicalsGroup(QTextStream* out);
	//	void physicalsScript(QTextStream* out,QString type,QMultiHash<QString,int> pHash);
		//获取在新组合体的索引,返回值大于0， 若返回0则为错误标记
		//type 1-点 2-线 3-面 4-实体
		int getShapeIndexInCompound(int setid, int index, int type);
		void mergeAllGeo();
		void mergeVisibleGeo();
		void mergeSelectGeo();


		QStringList getGridCoplanarScript();

	private:
		GUI::MainWindow* _mainwindow{};
		MainWidget::PreWindow* _preWindow{};
		GmshModule* _gmshModule{};

		QProcess _process{};
		ModuleBase::ProcessBar* _processBar{};

		int _dim{ -1 };
		TopoDS_Compound* _compounnd{};
		
		QMultiHash<int, int> _solidHash{};
		QMultiHash<int, int> _surfaceHash{};
		QString _elementType{};
		int _elementOrder{ -1 };
		int _method{ -1 };
		double _sizeFactor{ 0.0 };
		double _minSize{ 0.0 };
		double _maxSize{ 0.0 };
		bool _geoclean{ false };
		int _smoothIteration{ 0 };
		bool _isGridCoplanar{ false };
		QString _sizeAtPoints{};
		QString _sizeFields{};
		//QString _physicals{};
		bool _selectall{ false };
		bool _selectvisible{ false };
	};

}


#endif