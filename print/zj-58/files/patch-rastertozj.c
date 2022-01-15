--- rastertozj.c.orig	2019-04-29 04:18:11 UTC
+++ rastertozj.c
@@ -202,11 +202,7 @@ void finalizeJob() {
 }
 
 // sent at the end of every page
-#ifndef __sighandler_t
-typedef void (*__sighandler_t)(int);
-#endif
-
-__sighandler_t old_signal;
+__sighandler_t *old_signal;
 void finishPage() {
   signal(SIGTERM, old_signal);
 }
@@ -490,6 +486,11 @@ int main(int argc, char *argv[]) {
         DEBUGPRINT("--------Compress line from %d to %d bytes", tHeader.cupsBytesPerLine, width_bytes);
         iBytesChunk = compress_buffer(pRasterBuf, iBytesChunk,
                                       tHeader.cupsBytesPerLine, width_bytes);
+
+        /* see https://github.com/klirichek/zj-58/issues/35 */
+        if (iBytesChunk < 0) {
+            iBytesChunk = (tHeader.cupsBytesPerLine *iBlockHeight) + iBytesChunk;
+        }
       }
 
       // runaround for sometimes truncated output of cupsRasterReadPixels
