// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenFinisherTraumaResolverComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTraumaPaydownApplied, float, DebtCleared, float, BurnoutCleansed, float, WhisperSilenceDuration);

/**
 * UAshenFinisherTraumaResolverComponent
 * Manages the psychological and trauma debt resolution payouts for synchronized party finishers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherTraumaResolverComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherTraumaResolverComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Finisher Trauma")
	FOnTraumaPaydownApplied OnTraumaPaydownApplied;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Finisher Trauma")
	bool bWhispersSilenced = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Finisher Trauma")
	float SilenceTimer = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Finisher Trauma")
	void ResolveTraumaPaydown(EAshenPartyFinisherType FinisherType, float CurrentDebt, float CurrentBurnout);
};
