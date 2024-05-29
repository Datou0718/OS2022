#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"
#include "kernel/fs.h"
#define fail(msg) do {printf("FAILURE: " msg "\n"); failed = 1; goto done;} while (0);
static int failed = 0;


static void
public1()
{
  char buf[BSIZE];
  int fd, blocks;
  int target = 270;

  fd = open("big.file", O_CREATE | O_WRONLY);
  if(fd < 0){
    fail("bigfile: cannot open big.file for writing\n");
  } 

  blocks = 0;
  while(1){
    *(int*)buf = blocks;
    int cc = write(fd, buf, sizeof(buf));
    if(cc <= 0)
      break;
    blocks++;
    if (blocks % 100 == 0)
      printf(".");
    if(blocks == target)
      break;
  }
  printf("\nwrote %d blocks\n", blocks);
  if(blocks != target) {
    fail("bigfile: file is too small\n");
  }

  printf("public testcase 1: ok\n");

done:
  close(fd);
  unlink("big.file");
}

static void 
public2()
{
  char buf[BSIZE];
  int fd, blocks;
  int target = 6666;

  fd = open("big.file", O_CREATE | O_WRONLY);
  if(fd < 0){
    fail("bigfile: cannot open big.file for writing\n");
  }

  blocks = 0;
  while(1){
    *(int*)buf = blocks;
    int cc = write(fd, buf, sizeof(buf));
    if(cc <= 0)
      break;
    blocks++;
    if (blocks % 100 == 0)
      printf(".");
    if(blocks == target)
      break;
  }
  printf("\nwrote %d blocks\n", blocks);
  if(blocks != target) {
    fail("bigfile: file is too small\n");
  }
  printf("public testcase 2: ok\n");

done:
  close(fd);
  unlink("big.file");
}

static void 
cucumber1()
{
  char buf[BSIZE] = "sajdklfjasdkfjsadklfjashasdfhaskdfjaklsjfklsjdfkljsakldfjkasjdklfasjdlkhsl;ajkklsdhf;lashdfkjlashdz;nv.l13084yt92hg;aksngup9238yr29fh;aogbszuldhg89wa4ghwagi";
  int fd, blocks;
  int target = 7777;

  fd = open("big.file", O_CREATE | O_WRONLY);
  if(fd < 0){
    fail("bigfile: cannot open big.file for writing\n");
  }

  blocks = 0;
  while(1){
    *(int*)buf = blocks;
    int cc = write(fd, buf, sizeof(buf));
    if(cc <= 0)
      break;
    blocks++;
    if (blocks % 100 == 0)
      printf(".");
    if (blocks % 1000 == 0)
      printf(" %d\n", blocks) ;
    if(blocks == target)
      break;
  }
  close(fd);
  printf("\nwrote %d blocks\n", blocks);

  fd = open("big.file", O_CREATE | O_WRONLY | O_TRUNC);
  if(fd < 0){
    fail("bigfile: cannot open big.file for writing\n");
  }

  blocks = 0;
  while(1){
    *(int*)buf = blocks;
    int cc = write(fd, buf, sizeof(buf));
    if(cc <= 0)
      break;
    blocks++;
    if (blocks % 100 == 0)
      printf(".");
    if (blocks % 1000 == 0)
      printf(" %d\n", blocks) ;
    if(blocks == target)
      break;
  }

  printf("\nwrote %d blocks, again\n", blocks);
  if(blocks != target) {
    fail("bigfile: file is too small\n");
  }
  printf("cucumber testcase 1: ok\n");

done:
  close(fd);
  unlink("big.file");
}

static void 
cucumber2()
{
  char buf[BSIZE] = "sajdklfjasdkfjsadklfjashasdfhaskdfjaklsjfklsjdfkljsakldfjkasjdklfasjdlkhsl;ajkklsdhf;lashdfkjlashdz;nv.l13084yt92hg;aksngup9238yr29fh;aogbszuldhg89wa4ghwagi";
  int fd, blocks;
  int target = 66666;

  fd = open("big.file", O_CREATE | O_WRONLY);
  if(fd < 0){
    fail("bigfile: cannot open big.file for writing\n");
  }

  blocks = 0;
  while(1){
    *(int*)buf = blocks;
    int cc = write(fd, buf, sizeof(buf));
    if(cc <= 0)
      break;
    blocks++;
    if (blocks % 100 == 0)
      printf(".");
    if (blocks % 1000 == 0)
      printf(" %d\n", blocks) ;
    if(blocks == target)
      break;
  }
  printf("\nwrote %d blocks\n", blocks);
  if(blocks != target) {
    fail("bigfile: file is too small\n");
  }
  printf("cucumber testcase 2: ok\n");

done:
  close(fd);
  unlink("big.file");
}

int
main()
{
  public1();
  public2();
  cucumber1();
  cucumber2();
  exit(failed);
}
