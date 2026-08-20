// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenStaggeredCrisisTimelineValidator.generated.h"

/**
 * UAshenStaggeredCrisisTimelineValidator
 * Editor Subsystem auditing the 2.0-second staggered crisis timeline stages (0.0s time dilation, 0.2s physics freeze, 1.0s mark pulse, 1.5s parasite whisper).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenStaggeredCrisisTimelineValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateStaggeredCrisisTimeline();
};
