cmake_minimum_required(VERSION 3.22)
project(laforet VERSION 0.0.1)

find_package(JUCE CONFIG REQUIRED)

juce_add_plugin(laforet
    PLUGIN_MANUFACTURER_CODE SMPZ
    PLUGIN_CODE Lfrt
    FORMATS AU VST3 Standalone
    PRODUCT_NAME "laforet"
    NEEDS_WEB_BROWSER True
    NEEDS_CURL FALSE
)


target_sources(laforet
    PRIVATE
        src/PluginEditor.cpp
        src/PluginProcessor.cpp)


target_compile_definitions(laforet
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)


target_link_libraries(laforet
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
