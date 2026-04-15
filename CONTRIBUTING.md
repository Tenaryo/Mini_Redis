# Contributing to Redis_Cpp

Thanks for your interest in contributing! This guide will help you get started.

## Quick Start

### Prerequisites

- C++23 compiler (GCC 13+ recommended)
- CMake 3.21+
- Ninja (optional, but recommended for faster builds)

### Build

```bash
./build.sh          # Debug build (default)
./build.sh Release  # Release build
```

### Run Tests

```bash
./run_tests.sh
```

All tests must pass before submitting a PR.

## Development Workflow

1. **Fork** the repository and create your branch from `main`.
2. **Make changes** following the code style and conventions below.
3. **Add tests** for any new functionality or bug fix.
4. **Run tests** with `./run_tests.sh` to verify nothing is broken.
5. **Submit a pull request** with a clear description of the changes.

## Code Style

- Code formatting is enforced via `.clang-format` (LLVM-based style).
- Run formatting check before committing:

```bash
find src tests -name '*.cpp' -o -name '*.hpp' | xargs clang-format --dry-run --Werror
```

- To auto-format:

```bash
find src tests -name '*.cpp' -o -name '*.hpp' | xargs clang-format -i
```

### Key Conventions

- **C++23**: Use modern C++ features (`std::expected`, `std::variant`, `std::from_chars`, etc.).
- **No external dependencies**: Only standard library and POSIX APIs.
- **No comments in code**: The codebase follows a no-comments convention. Write self-documenting code.
- **Header-only where possible**: Utility types live in `.hpp` files; implementation details in `.cpp` files.

## Commit Messages

Follow the [Conventional Commits](https://www.conventionalcommits.org/) format:

```
type: short description
```

**Types:**

| Type | Usage |
|------|-------|
| `feat` | New feature or command |
| `fix` | Bug fix |
| `refactor` | Code restructuring without behavior change |
| `test` | Adding or updating tests |
| `docs` | Documentation changes |
| `ci` | CI/CD changes |
| `chore` | Build, config, or tooling changes |

**Examples:**
```
feat: implement ZPOPMIN command
fix: handle empty stream in XRANGE with special IDs
refactor: extract connection buffer logic to shared utility
test: add ZPOPMIN command tests
```

## Adding a New Command

1. Add the command handler in `src/handler/command_handler.cpp`.
2. Register it in the command dispatch table.
3. Add any store-level logic in `src/store/`.
4. Create a test file `tests/test_<command>.cpp`.
5. Update `README.md` with the new command.

## Reporting Issues

- Use the [Bug Report](../../issues/new?template=bug_report.yml) template for bugs.
- Use the [Feature Request](../../issues/new?template=feature_request.yml) template for suggestions.

## Pull Request Checklist

Before submitting a PR, make sure:

- [ ] All tests pass (`./run_tests.sh`)
- [ ] Code is formatted (`clang-format --dry-run --Werror`)
- [ ] No compiler warnings with `-Wall -Wextra -Werror`
- [ ] Commit messages follow conventional commit format
- [ ] New features include tests

## License

By contributing, you agree that your contributions will be licensed under the [MIT License](LICENSE).
