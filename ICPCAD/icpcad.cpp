#include "icpcad.h"
#include "ui_icpcad.h"


TopoDS_Shape
MakeBottle(const Standard_Real myWidth , const Standard_Real myHeight , const Standard_Real myThickness);

ICPCAD::ICPCAD(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ICPCAD)
{
    ui->setupUi(this);
    //BRepPrimAPI_MakeSphere mkSphere(5.);
    BRepPrimAPI_MakeBox mkBox(1., 2., 3);
    //const TopoDS_Shape& shape = mkSphere.Shape();
    const TopoDS_Shape& shape = mkBox.Shape();
    vtkNew<vtkNamedColors> colors;
    vtkNew<IVtkTools_ShapeDataSource> occSource;
    occSource->SetShape(new IVtkOCC_Shape(shape));

    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(occSource->GetOutputPort());

    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);

    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(actor);
    renderer->SetBackground(colors->GetColor3d("SteelBlue").GetData());

    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    renderWindow->AddRenderer(renderer);
    renderWindow->SetWindowName("occvtk");
    setCentralWidget(ui->openGLWidget);
    ui->openGLWidget->setRenderWindow(renderWindow);
}

ICPCAD::~ICPCAD()
{
    delete ui;
}

