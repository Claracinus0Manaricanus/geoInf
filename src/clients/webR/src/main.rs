use yew::prelude::*;
use yew::events::*;
use gloo_console::log;

/*struct TableElement{
    ID:i32,
    name:String,
    climate:String,
    soil:String,
    image:String,
}*/


fn main() {
    yew::Renderer::<App>::new().render();
}


#[function_component(App)]
fn app()->Html{
    let mut cuteVar:i32=0;

    let numIncreaser=Callback::from(move|event:MouseEvent|{log!("de")});

    html!{
        <>
        <div style="position:fixed;left:45%;">
            <p style="font-size:34px;">{cuteVar}</p>
            <button style="padding-left:50px;padding-right:50px;" onclick={numIncreaser}><p style="font-size:24px;">{"+1"}</p></button>
        </div>
        </>
    }
}