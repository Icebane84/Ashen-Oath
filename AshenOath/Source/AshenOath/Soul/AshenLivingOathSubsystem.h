// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenLivingOathSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenLivingOathType : uint8
{
	None,
	OathOfUnbrokenFellowship,
	OathOfRadiantMercy,
	OathOfTheShadowSovereign,
	OathOfSilentVigil
};

UENUM(BlueprintType)
enum class EAshenOathState : uint8
{
	Unsworn,
	Active,
	Fulfilled,
	Fractured,
	Forsaken
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLivingOathStateChanged, EAshenLivingOathType, OathType, EAshenOathState, NewState);

/**
 * UAshenLivingOathSubsystem
 * GameInstance Subsystem managing sworn Living Oaths, tenet fulfillment meters, and psychological consequences.
 */
UCLASS()
class ASHENOATH_API UAshenLivingOathSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Living Oath")
	FOnLivingOathStateChanged OnLivingOathStateChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Living Oath")
	EAshenLivingOathType ActiveOath = EAshenLivingOathType::None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Living Oath")
	EAshenOathState OathState = EAshenOathState::Unsworn;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Living Oath")
	float OathFulfillmentPercent = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Living Oath")
	bool SwearLivingOath(EAshenLivingOathType NewOath);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Living Oath")
	void ProgressOathFulfillment(float DeltaPercent);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Living Oath")
	void FractureLivingOath();
};
