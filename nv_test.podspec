#
# Be sure to run `pod lib lint nv_test.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'nv_test'
  s.version          = '0.1.0'
  s.summary          = 'this is my first cocoapods lib for testing my nv lib'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
This is my first cocoapods lib for testing my nv lib so that we can create lib for users
                       DESC

  s.homepage         = 'https://github.com/ashraf-nv/nv_test'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'ashraf-nv' => 'ashraf@notifyvisitors.com' }
  s.source           = { :git => 'https://github.com/ashraf-nv/nv_test.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'nv_test/Classes/**/*'
  s.resources = "nv_test/Assets/**/*.{png,jpg,plist}"
  s.vendored_library = 'nv_test/Classes/libnotifyvisitors_5_1_3.a'
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
  
  
end
