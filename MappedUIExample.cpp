#include "MappedUIExample.h"

#include <Urho3D/UI/Slider.h>
#include <Urho3D/UI/UIEvents.h>

MappedUIExample::MappedUIExample(Context * context) : UIElement(context)
{
    auto * uiHolder = new UIElement(context_);
    uiHolder->SetLayout(LM_VERTICAL);
    AddChild(uiHolder);

    Slider * slider = new Slider(context_);
    slider->SetStyleAuto();
    uiHolder->AddChild(slider);
    if(AddMappedElement("Slider 1", slider, &MappedUIExample::ExampleElementChanged)){
        SubscribeToEvent(slider, E_SLIDERCHANGED, URHO3D_HANDLER(MappedUIExample, HandleItemChanged));
    }

    AddMappedKey(Key::KEY_ESCAPE, &MappedUIExample::ExampleKeyPress);
}

void MappedUIExample::ExampleElementChanged(UIElement* parentClass, UIElement* element)
{
    //this will be called when the slider is changed
    if(parentClass != nullptr && element != nullptr){
        /// element is the slider

        /// parent class is MappedUIExample calling object
        /// say we want to disable all mapped elements of the caller ->
        parentClass->EnableMapped(false);
        /// say we want to show this(enable and set visibility of this and all mapped children)
        parentClass->ShowMapped(true);
        /// say we want to get the mapped caller parent of the recieved element
        auto * mappedCaller = element->GetMappedParent();
        /// in this case the caller would be the ExampleElentChanged object

        /// Show the Slider
        parentClass->ShowMappedChild("Slider 1",true);
        /// Enable the Slider
        parentClass->EnableMappedChild("Slider 1",true);
}

void ExampleElementChanged::ExampleKeyPress(UIElement* parentClass, UIElement* element)
{
    //escape key triggers this
    if(parentClass != nullptr){
        // do something
        auto * root = parentClass->GetSubsystem<UI>()->GetRoot();
    }
}
