# Makefile

define add_example
	@echo "" >> README.md
	@echo "## $(1)" >> README.md
	@echo "" >> README.md
	@python $(1).py
	@python get_readme_block.py $(1).stl >> README.md
endef

build:
	@rm -rf README.md
	@echo "# Examples" >> README.md
	$(call add_example,simple)
	$(call add_example,cylinder)
	$(call add_example,torus)
	$(call add_example,intersection)
	$(call add_example,sphere)
	$(call add_example,convex_hull)
.PHONY: build
