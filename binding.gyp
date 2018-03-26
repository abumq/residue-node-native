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
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
    },
  ],
}
