#!bin/csh

if( `uname -n` != "nthucad" ) then
	set tooldir
	switch(`lsb_release -sr | cut -d. -f1`)
	case 5:
		set tooldir=/tools/linux/gnu/centos5/toolkits
		setenv PYTHONHOME /tools/linux/gnu/centos5/toolkits
		breaksw
	case 6:
		set tooldir=/tools/linux/gnu/centos6/toolkits
		breaksw
	default:
		echo "Didn't have any toolkits can run on" `lsb_release -ds`
		breaksw
	endsw

	setenv PATH "${tooldir}/bin:/usr/bin:/bin:/usr/local/bin:${PATH}"

	if ( $?LD_LIBRARY_PATH ) then
		setenv LD_LIBRARY_PATH "${tooldir}/lib64:${tooldir}/lib:${LD_LIBRARY_PATH}"
	else
		setenv LD_LIBRARY_PATH "${tooldir}/lib64:${tooldir}/lib"
	endif

	if ( $?MANPATH ) then
		setenv MANPATH "${tooldir}/man:${MANPATH}"
	else
		setenv MANPATH "${tooldir}/man"
	endif

	if ( $?PYTHONPATH) then
		setenv PYTHONPATH "${tooldir}/lib/python:${PYTHONPATH}"
	else
		setenv PYTHONPATH "${tooldir}/lib/python"
	endif

	setenv CC `which gcc`
	setenv CXX `which g++`
endif
