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
      "xcode_settings": {
        "OTHER_CFLAGS": [
          "-fexceptions",
          "-std=c++11",
          "-stdlib=libc++"
        ],
      },
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
    },
  ],
}
