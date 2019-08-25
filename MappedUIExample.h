#include <Urho3D/UI/UIElement.h>

using namespace Urho3D;

class MappedUIExample : public UIElement
{
    URHO3D_OBJECT(MappedUIExample, UIElement);
public:
    MappedUIExample(Context* context);

    static void ExampleElementChanged(UIElement* parentClass, UIElement* element);
    static void ExampleKeyPress(UIElement * parentClass, UIElement* element)
};
