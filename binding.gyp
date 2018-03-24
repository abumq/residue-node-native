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
        "ELPP_THREAD_SAFE",
        "_HAS_EXCEPTIONS=1"
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}
