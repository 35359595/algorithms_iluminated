# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.algorithms_illuminated.Debug:
/Users/jony/projects/cpp/algorithms_illuminated/_build/Debug/algorithms_illuminated:
	/bin/rm -f /Users/jony/projects/cpp/algorithms_illuminated/_build/Debug/algorithms_illuminated


PostBuild.algorithms_illuminated.Release:
/Users/jony/projects/cpp/algorithms_illuminated/_build/Release/algorithms_illuminated:
	/bin/rm -f /Users/jony/projects/cpp/algorithms_illuminated/_build/Release/algorithms_illuminated


PostBuild.algorithms_illuminated.MinSizeRel:
/Users/jony/projects/cpp/algorithms_illuminated/_build/MinSizeRel/algorithms_illuminated:
	/bin/rm -f /Users/jony/projects/cpp/algorithms_illuminated/_build/MinSizeRel/algorithms_illuminated


PostBuild.algorithms_illuminated.RelWithDebInfo:
/Users/jony/projects/cpp/algorithms_illuminated/_build/RelWithDebInfo/algorithms_illuminated:
	/bin/rm -f /Users/jony/projects/cpp/algorithms_illuminated/_build/RelWithDebInfo/algorithms_illuminated




# For each target create a dummy ruleso the target does not have to exist
