/*
 * In ReasonML, re-exporting a module allows you to make it available under a
 * new or existing module name within the current module's namespace. This is
 * similar to 'exporting' in JavaScript or TypeScript, where you can re-export
 * something from another module.
 *
 * Here, `module Fetch = Fetch;` within `src/bindings/Fetch.re` is
 * re-exporting the `Fetch` module. It makes `Fetch` accessible as part of
 * the `Fetch` module. This is particularly useful in ReasonMl/Dune for
 * organizing code and creating clear module hierarchies or APIs.
 *
 * This approach is beneficial in ReasonML/Dune for structuring code more
 * clearly. It allows for creating well-defined module hierarchies and APIs, by
 * grouping related functionality and making it accessible under a unified
 * namespace. Such organization aids in maintaining clarity and ease of use in
 * larger codebases.
 *
 * In a Dune-managed project, each module corresponds to a file by default, so
 * this pattern is often used to expose certain modules at a higher level for
 * easier access by other parts of the application.
 */
module Fetch = Fetch;
