{
  "targets": [
    {
      "target_name": "residue_native",
      "sources": [
        "src/residue_native.cc"
      ],
      "libraries": [
        "-lresidue"
      ],
      "defines": [
        "ELPP_THREAD_SAFE"
      ],
      "include_dirs": [
        "include", 
        "<!(node -e \"require('nan')\")"
      ],
      "cflags!": [
        "-fno-exceptions"
      ],
      "cflags_cc!": [
        "-fno-exceptions"
        "-Wall"
      ],
    },
  ],
}
