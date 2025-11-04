# Documentation Guide

## Generating Documentation

This project uses Doxygen to generate comprehensive HTML documentation from the source code comments.

### Prerequisites

Install Doxygen:
```bash
# On Fedora/RHEL
sudo dnf install doxygen

# On Ubuntu/Debian
sudo apt-get install doxygen

# On macOS
brew install doxygen
```

Optional (for diagram generation):
```bash
# Install Graphviz for class diagrams
sudo dnf install graphviz
```

### Generate Documentation

To generate the documentation:

```bash
# From the project root directory
doxygen Doxyfile
```

This will create a `docs` directory with the following structure:
```
docs/
├── html/          # HTML documentation
│   └── index.html # Main documentation page
└── ...
```

### View Documentation

Open the generated documentation in your browser:

```bash
# On Linux
xdg-open docs/html/index.html

# On macOS
open docs/html/index.html

# On Windows
start docs/html/index.html
```

Or simply navigate to `docs/html/index.html` in your file browser and open it.

## Documentation Structure

The documentation includes:

- **Class List**: All classes in the project with their descriptions
- **File List**: All source and header files
- **Class Hierarchy**: Inheritance relationships
- **Class Members**: Detailed documentation of all methods and attributes
- **File Documentation**: File-level comments and included files
- **Namespace Documentation**: Organized by namespace

## Doxygen Configuration

The `Doxyfile` configuration includes:

- **Project Name**: Chaos Compilers Plant Nursery System
- **Input Directories**: `src/`, `tests/`, `gui/`, `README.md`
- **Output**: HTML format (LaTeX disabled)
- **Extract All**: Yes (documents all classes and members)
- **Extract Private**: Yes (includes private members)
- **Source Browser**: Enabled (allows browsing source code)
- **Tree View**: Enabled (hierarchical navigation)
- **Search Engine**: Enabled (for searching documentation)

## Writing Doxygen Comments

### File Comments
```cpp
/**
 * @file ClassName.cpp
 * @brief Brief description of what this file contains
 * @author Chaos_Compilers
 * @date 2025
 */
```

### Class Comments
```cpp
/**
 * @class ClassName
 * @brief Brief description of the class
 * 
 * Detailed description of what the class does,
 * its purpose, and how it fits into the system.
 */
class ClassName {
    // ...
};
```

### Method Comments
```cpp
/**
 * @brief Brief description of what the method does
 * 
 * Detailed description if needed.
 * 
 * @param paramName Description of the parameter
 * @return Description of return value
 * @throws ExceptionType When this exception is thrown
 */
ReturnType methodName(ParamType paramName);
```

### Member Variable Comments
```cpp
int counter;  ///< Brief description of the member variable
```

## Updating Documentation

Whenever you modify code:

1. Update or add Doxygen comments to reflect changes
2. Regenerate documentation: `doxygen Doxyfile`
3. Review the generated HTML to ensure quality
4. Commit both code changes and updated comments (but not the `docs/` directory)

## Troubleshooting

### Common Issues

**"doxygen: command not found"**
- Install Doxygen as shown in Prerequisites

**"No documentation generated"**
- Check that you're running `doxygen Doxyfile` from the project root
- Verify the `INPUT` paths in Doxyfile are correct

**"Warnings about undocumented members"**
- These are normal - add documentation to eliminate them
- Or set `WARN_IF_UNDOCUMENTED = NO` in Doxyfile (not recommended)

**"Diagrams not generated"**
- Install Graphviz: `sudo dnf install graphviz`
- Set `HAVE_DOT = YES` in Doxyfile

## CI/CD Integration

To generate documentation automatically in CI/CD, add to `.github/workflows/ci-cd.yml`:

```yaml
- name: Generate Documentation
  run: |
    sudo apt-get install -y doxygen
    doxygen Doxyfile
    
- name: Deploy to GitHub Pages
  uses: peaceiris/actions-gh-pages@v3
  with:
    github_token: ${{ secrets.GITHUB_TOKEN }}
    publish_dir: ./docs/html
```

## Additional Resources

- [Doxygen Manual](https://www.doxygen.nl/manual/)
- [Doxygen Quick Reference](https://www.doxygen.nl/manual/docblocks.html)
- [Special Commands](https://www.doxygen.nl/manual/commands.html)
