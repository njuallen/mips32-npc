all_targets := rv32_1stage rv32_noop
 
include ./prefix.mk

MK_TARGET_PROC?=rv32_1stage

all: $(patsubst %,emulator/%/emulator,$(all_targets))

shell:
	$(SBT) "project ${MK_TARGET_PROC}" shell

run-emulator: all
	make -C $(patsubst %,emulator/%,$(all_targets)) run

clean-tests:
	make -C $(patsubst %,emulator/%,$(all_targets)) clean-tests

clean:
	-find sbt -type d -name target -exec rm -rf {} \+
	for d in $(patsubst %,emulator/%,$(all_targets)) ; do \
		make -C $$d clean ; \
	done

emulator/%/emulator:
	make -C $(dir $@)

.PHONY: run-emulator clean clean-tests

# Because we are using recursive makefiles and emulator is an actual file.
emulator/rv32_1stage/emulator: $(wildcard $(srcDir)/src/common/*.scala) \
                                 $(wildcard $(srcDir)/src/rv32_1stage/*.scala)

emulator/rv32_noop/emulator: $(wildcard $(srcDir)/src/common/*.scala) \
                                 $(wildcard $(srcDir)/src/rv32_noop/*.scala)
