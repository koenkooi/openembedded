DESCRIPTION = "Koreanized JumpX input method"
SECTION = "opie/inputmethods"
PRIORITY = "optional"
LICENSE = "GPL"
RDEPENDS_${PN} = "opie-pics"
APPNAME = "qkjumpx"


S = "${WORKDIR}/kjumpx"

inherit opie

pkg_postinst() {
#!/bin/sh
if [ -n "$D" ]; then exit 1; fi
if pidof -s qpe >/dev/null; then
  /usr/bin/qcop QPE/TaskBar "reloadInputMethods()"
else
  exit 0
fi

}

pkg_postrm() {
#!/bin/sh
if [ -n "$D" ]; then exit 1; fi
/usr/bin/qcop QPE/TaskBar "reloadInputMethods()"
}

# FILES plugins/inputmethods/libqkjumpx.so* pics/kjumpx/*
do_install() {
	install -d ${D}${palmtopdir}/pics/kjumpx/
	install -m 0644 ${WORKDIR}/pics/kjumpx/*.png ${D}${palmtopdir}/pics/kjumpx/
}

