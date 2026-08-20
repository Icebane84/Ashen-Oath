// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenWhisperingWindSubsystem.generated.h"

/**
 * UAshenWhisperingWindSubsystem
 * GameInstance Subsystem managing 3D-spatialized atmospheric whispers and dynamic voice barks scaling with Isolation and Integration Debt.
 */
UCLASS()
class ASHENOATH_API UAshenWhisperingWindSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Audio")
	float CurrentWhisperIntensity = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateWhisperIntensity(float Isolation, float IntegrationDebt);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void SetCorruptionInput(float InCorruption) { CurrentWhisperIntensity = FMath::Clamp(InCorruption, 0.0f, 1.0f); }

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	float GetWhisperIntensity() const { return CurrentWhisperIntensity; }

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	float GetWhisperVolume() const { return CurrentWhisperIntensity * 0.85f; }

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerSpatializedBark(FVector Location, FName BarkID);
};
