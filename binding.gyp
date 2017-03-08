{
    "targets": [
        {
            "target_name": "addon",
            "sources": ["string-low-level.cc", "string-low-level-lib-wrapper.cc" ],
            "cflags!": [ '-fno-exceptions' ],
            "cflags_cc!": [ '-fno-exceptions' ],
            "conditions": [
                [ 'OS!="mac"', {
                    "cflags+": [ "-std=c++11" ],
                    "cflags_c+": [ "-std=c++11" ],
                    "cflags_cc+": [ "-std=c++11" ],
                }],
                ['OS=="mac"', {
                'xcode_settings': {
                    'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                    'MACOSX_DEPLOYMENT_TARGET': '10.7',
                    'OTHER_CFLAGS': ['-std=c++11','-stdlib=libc++'],
                }
                }]
            ],
            "include_dirs" : [ "<!(node -e \"require('nan')\")" ]
            
        }
    ]
}