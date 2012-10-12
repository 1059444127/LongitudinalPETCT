/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

#ifndef __qSlicerLongitudinalPETCTFindingSelectionWidget_h
#define __qSlicerLongitudinalPETCTFindingSelectionWidget_h

// Qt includes
#include <QWidget>
#include <ctkVTKObject.h>

// LongitudinalPETCTFindingSelection Widgets includes
#include "qSlicerLongitudinalPETCTModuleWidgetsExport.h"


class qSlicerLongitudinalPETCTFindingSelectionWidgetPrivate;
class vtkMRMLNode;
class qMRMLNodeComboBox;
class vtkMRMLScene;
class vtkMRMLLongitudinalPETCTReportNode;



/// \ingroup Slicer_QtModules_LongitudinalPETCT
class Q_SLICER_LONGITUDINALPETCT_MODULE_WIDGETS_EXPORT qSlicerLongitudinalPETCTFindingSelectionWidget
  : public QWidget
{
  Q_OBJECT
  QVTK_OBJECT
  Q_PROPERTY(vtkMRMLScene* mrmlScene READ mrmlScene WRITE setMRMLScene)
  Q_PROPERTY(bool selectionEnabled READ selectionEnabled WRITE setSelectionEnabled)
  Q_PROPERTY(bool roiVisibility READ roiVisibility WRITE setROIVisibility)
  Q_PROPERTY(bool placeROIChecked READ placeROIChecked WRITE setPlaceROIChecked)



public:
  typedef QWidget Superclass;
  qSlicerLongitudinalPETCTFindingSelectionWidget(QWidget *parent=0);
  virtual ~qSlicerLongitudinalPETCTFindingSelectionWidget();

  Q_INVOKABLE void setMRMLScene(vtkMRMLScene* mrmlScene);
  vtkMRMLScene* mrmlScene();

  void setSelectionEnabled(bool enabled);
  bool selectionEnabled();

  void setROIVisibility(bool visibility);
  bool roiVisibility();

  bool placeROIChecked();
  void setPlaceROIChecked(bool checked);

  Q_INVOKABLE qMRMLNodeComboBox* mrmlNodeComboBoxFinding();
  Q_INVOKABLE void setEditorWidget(QWidget* editorWidget);

  Q_INVOKABLE void setReportNode(vtkMRMLLongitudinalPETCTReportNode* reportNode);
  Q_INVOKABLE vtkMRMLLongitudinalPETCTReportNode* reportNode();

signals:
  void findingNodeAddedByUser(vtkMRMLNode* node);
  void roiVisibilityChanged(bool visible);
  void placeROIChecked(bool checked);
  void addSegmentationToFinding();

public slots:
  void updateView();
  void hideAddButton(bool hide);

protected:
  QScopedPointer<qSlicerLongitudinalPETCTFindingSelectionWidgetPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(qSlicerLongitudinalPETCTFindingSelectionWidget);
  Q_DISABLE_COPY(qSlicerLongitudinalPETCTFindingSelectionWidget);



};

#endif