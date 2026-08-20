// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenKernelSerafinaResonanceSubsystem.generated.h"

/**
 * UAshenKernelSerafinaResonanceSubsystem
 * World Subsystem computing Serafina identity resonance from the live FSoulStateVector.
 * Subscribes to FOnSoulStateVectorInvalidated — governs support spell availability and companion spatial offset.
 */
UCLASS()
class ASHENOATH_API UAshenKernelSerafinaResonanceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	float SerafinaResonanceScore = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	bool bSupportSpellsAvailable = true;

	UFUNCTION()
	void OnSoulStateVectorInvalidated(const FSoulStateVector& NewStateVector);
};
