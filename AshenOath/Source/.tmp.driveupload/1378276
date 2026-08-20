// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenWeaponRuneInscriptionStressTester.generated.h"

/**
 * UAshenWeaponRuneInscriptionStressTester
 * Editor Subsystem stress testing 1,000 continuous weapon combat events and dynamic dynamic mesh rune baking.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenWeaponRuneInscriptionStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunWeaponRuneInscriptionStressTest();
};
