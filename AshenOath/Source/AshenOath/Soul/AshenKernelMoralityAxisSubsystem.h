// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenKernelMoralityAxisSubsystem.generated.h"

/**
 * UAshenKernelMoralityAxisSubsystem
 * World Subsystem maintaining the full multi-axis moral weight spectrum (non-binary Compassion / Pragmatism / Courage).
 * Subscribes to FOnSoulStateVectorInvalidated — translates BehavioralProfile to moral disposition without binary good/evil collapse.
 */
UCLASS()
class ASHENOATH_API UAshenKernelMoralityAxisSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	float CompassionAxis = 0.5f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	float PragmatismAxis = 0.5f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	float CourageAxis = 0.5f;

	UFUNCTION()
	void OnSoulStateVectorInvalidated(const FSoulStateVector& NewStateVector);
};
