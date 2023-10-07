use yew::prelude::*;
use yew::events::*;

#[function_component(App)]
fn app()->Html{
    let cuteVar:&str="yep";
    html!{
        <>
            <div style="inline-size:50%;block-size:100%;background-color:rgba(154,143,200,0.5);padding:10px;">
                <h1>{"Sample Text"}</h1>
                <p style="color:red;padding:4px;">{cuteVar}</p>
                <button>{"place of text for thy button"}</button>
            </div>
        </>
    }
}

fn main() {
    yew::Renderer::<App>::new().render();
}
