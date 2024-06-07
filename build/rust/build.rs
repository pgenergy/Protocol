use glob::glob;
use std::path::PathBuf;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    // Collect all .proto files in the proto directory
    let proto_files: Vec<PathBuf> = glob("proto/*.proto")?
        .filter_map(Result::ok)
        .collect();

    // Convert PathBuf to &str for prost_build::compile_protos
    let proto_files_str: Vec<&str> = proto_files.iter()
        .map(|path| path.to_str().unwrap())
        .collect();

    prost_build::compile_protos(&proto_files_str, &["proto/"])?;
    Ok(())
}
