{
  "targets": [
    {
      "target_name": "residue-native",
      "sources": [
        "src/residue-native.cc"
      ],
      "libraries": [
        "-lresidue"
      ],
      "defines": [
        "ELPP_THREAD_SAFE",
        "_GLIBCXX_USE_CXX11_ABI=0"
      ],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "conditions": [
        ['OS=="mac"', {
          "xcode_settings": {
            "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
          },
          "ccflags": [
            "-mmacosx-version-min=10.7",
            "-std=c++11",
            "-stdlib=libc++",
          ],
        }],
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "<!(node -e \"require('libresidue')\")"
      ],
    },
  ],
}
