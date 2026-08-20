// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Combat/AshenControllerFrictionTypes.h"
#include "AshenControllerFrictionSubsystem.generated.h"

/**
 * UAshenControllerFrictionSubsystem
 * GameInstance Subsystem managing real-time DualSense controller friction, input buffer delays, and struggle phase dispatch.
 */
UCLASS()
class ASHENOATH_API UAshenControllerFrictionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Friction")
	EStrugglePhase CurrentStrugglePhase = EStrugglePhase::Phase1_DiscordantHum;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Friction")
	float ArtificialInputDelayMilliseconds = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Friction")
	void CalculateInputBufferFriction(float CorruptionAmount);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Friction")
	void SetStrugglePhase(EStrugglePhase NewPhase);
};
