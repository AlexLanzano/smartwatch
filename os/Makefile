dirs = arch core drivers
bins = $(patsubst %, %/obj.a, $(dirs))
clean-dirs = $(patsubst %, %__clean__, $(dirs))
conf = tools/kconfig/conf

all: os.bin

.PHONY: %_defconfig
%_defconfig: configs/%_defconfig $(conf)
	$(conf) --syncconfig --defconfig $< Kconfig

$(conf): tools/kconfig
	make -C tools/kconfig/

tools/kconfig:
	git submodule update --init --recursive

os.bin: $(bins)
	make -f Makefile.os bins="$(bins)"

$(bins): $(dirs)

.PHONY: $(dirs)
$(dirs):
	make -f Makefile.build dir=$@ build-bin=obj.a

.PHONY: clean
clean: $(clean-dirs)
	rm -rf $(bins) os.elf os.bin

$(clean-dirs):
	make -f Makefile.clean dir=$@

.PHONY: mrproper
mrproper: clean
	rm -rf include/generated include/config .config .deps
