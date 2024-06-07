pub extern crate prost;

include!(concat!(env!("OUT_DIR"), "/energyleaf.rs"));
pub mod ml_api {
    include!(concat!(env!("OUT_DIR"), "/energyleaf_ml.rs"));
}
