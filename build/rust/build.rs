use glob::glob;
use std::path::PathBuf;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    // Collect all .proto files in the proto directory
    let proto_files: Vec<PathBuf> = glob("proto/*.proto")?.filter_map(Result::ok).collect();

    // Convert PathBuf to &str for prost_build::compile_protos
    let proto_files_str: Vec<&str> = proto_files
        .iter()
        .map(|path| path.to_str().unwrap())
        .collect();

    prost_build::compile_protos(&proto_files_str, &["proto/"])?;

    let out_dir = PathBuf::from(std::env::var("OUT_DIR").unwrap());
    let mod_file_path = out_dir.join("mod.rs");

    let mut mod_file_content = String::new();

    for entry in std::fs::read_dir(&out_dir)? {
        let entry = entry?;
        let path = entry.path();

        if let Some(extension) = path.extension() {
            if extension == "rs" && entry.file_name() != "mod.rs" {
                let file_stem = path.file_stem().unwrap().to_str().unwrap();
                mod_file_content.push_str(&format!("pub mod {};\n", file_stem));
            }
        }
    }

    std::fs::write(mod_file_path, mod_file_content)?;
    Ok(())
}
