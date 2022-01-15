PORTNAME=	zj-58
PORTVERSION=	0.0.${ZJ_58_DATE}
CATEGORIES=	print
PKGNAMEPREFIX=	cups-

MAINTAINER=	y@trombik.org
COMMENT=	CUPS filter for ESC/POS thermal printers

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	cups-filters>=0:print/cups-filters
LIB_DEPENDS=	libcups.so:print/cups

USES=	cmake
USE_GITHUB=	yes
ZJ_58_TAGNAME=	6474356
# the date of `ZJ_58_TAGNAME` commit
ZJ_58_DATE=	20190429
GH_TUPLE=	klirichek:${PORTNAME}:${ZJ_58_TAGNAME}

CUPS_FILTER_DIR=	${PREFIX}/libexec/cups/filter
ZJ_58_MODEL_DIR=	${PREFIX}/share/cups/model/zjiang

pre-configure:
	${REINPLACE_CMD} \
		-e 's|%%CUPS_FILTER_DIR%%|${CUPS_FILTER_DIR}|' \
		-e 's|%%ZJ_58_MODEL_DIR%%|${ZJ_58_MODEL_DIR}|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
