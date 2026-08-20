// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterReleasePackagingVerifier.generated.h"

/**
 * UAshenProductFilterReleasePackagingVerifier
 * Subsystem verifying shipping target asset packaging compliance.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterReleasePackagingVerifier : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool VerifyReleasePackagingCompliance();
};
