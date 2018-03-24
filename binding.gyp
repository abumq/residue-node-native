{
  "targets": [
    {
      "target_name": "residue_native",
      "sources": [
        "src/residue_native.cc"
      ],
      "libraries": [
        "-lresidue-static"
      ],
      "defines": [
        "ELPP_THREAD_SAFE"
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}
