/******************************************************************************

  This source file is part of the Avogadro project.

  Copyright 2012 Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef AVOGADRO_QTPLUGINS_VANDERWAALS_H
#define AVOGADRO_QTPLUGINS_VANDERWAALS_H

#include <avogadro/qtgui/sceneplugin.h>

namespace Avogadro {
namespace QtPlugins {

/*!
 * \brief Render the molecule as Van der Waals spheres.
 * \author Marcus D. Hanwell
 */
class VanDerWaals : public QtGui::ScenePlugin
{
  Q_OBJECT

public:
  explicit VanDerWaals(QObject *parent = 0);
  ~VanDerWaals();

  void process(const Core::Molecule &molecule, Rendering::Scene &scene);

  QString name() const { return tr("Van der Waals"); }

  QString description() const { return tr("Simple display of VdW spheres."); }

  bool isEnabled() const;

  void setEnabled(bool enable);

private:
  bool m_enabled;
};


class VanDerWaalsFactory : public QObject, public QtGui::ScenePluginFactory
{
  Q_OBJECT
  Q_INTERFACES(Avogadro::QtGui::ScenePluginFactory)
  SCENE_PLUGIN_FACTORY(VanDerWaals, "Van der Waals spheres")
};

}
}

#endif // AVOGADRO_QTPLUGINS_VANDERWAALS_H