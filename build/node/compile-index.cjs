const fs = require('node:fs');
const path = require('node:path');

const libDir = path.join(__dirname, 'src', 'lib');
const indexPath = path.join(__dirname, 'src', 'lib', 'index.ts');

fs.readdir(libDir, (err, files) => {
    if (err) {
        console.error('Error reading directory:', err);
        return;
    }

    const tsFiles = files.filter((file) => file.endsWith('.ts') && file !== 'index.ts');
    const exports = tsFiles
        .map((file) => {
            const fileNameWithoutExt = path.basename(file, '.ts');
            const exportName = fileNameWithoutExt.replace(/-/g, '_').toLowerCase();
            return `export * as ${exportName} from './${fileNameWithoutExt}';`;
        })
        .join('\n');

    fs.writeFile(indexPath, exports, (err) => {
        if (err) {
            console.error('Error writing file:', err);
            return;
        }

        console.log('Index file created successfully');
    });
});
