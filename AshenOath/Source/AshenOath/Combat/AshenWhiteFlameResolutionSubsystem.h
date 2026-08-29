// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Combat/AshenWhiteFlameTypes.h"
#include "AshenWhiteFlameResolutionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWhiteFlameResolutionActivatedSignature, float, ClearedDebt, float, DurationSeconds);

/**
 * UAshenWhiteFlameResolutionSubsystem
 * GameInstance Subsystem managing the White Flame Resolution activation conditions (Resolve >= 0.90, Burnout >= 0.65), 12.0s catharsis duration, and 100% debt eradication.
 */
UCLASS()
class ASHENOATH_API UAshenWhiteFlameResolutionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | WhiteFlame")
	FWhiteFlameResolutionPayload CurrentResolutionPayload;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | WhiteFlame|Events")
	FOnWhiteFlameResolutionActivatedSignature OnWhiteFlameResolutionActivated;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | WhiteFlame")
	bool EvaluateResolutionReadiness(float KaelenResolve, float SerafinaBurnout);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | WhiteFlame")
	bool ActivateWhiteFlameResolution(float CurrentIntegrationDebt, float& OutClearedDebt);

	/** World-aware activation that automatically purges world debt and fatigue subsystems */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | WhiteFlame")
	bool ActivateWhiteFlameWithWorldContext(UWorld* WorldContext, float& OutClearedDebt);
};
