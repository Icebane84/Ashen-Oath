// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenPartySyncFinisherGASAbility.generated.h"

/**
 * UAshenPartySyncFinisherGASAbility
 * GAS ability driving execution slow-mo (0.2x), multi-character anim montage synchronization,
 * invulnerability frames, and camera letterboxing.
 */
UCLASS()
class ASHENOATH_API UAshenPartySyncFinisherGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenPartySyncFinisherGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Finisher GAS")
	float FinisherSlowMoDilation = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Finisher GAS")
	float FinisherDamage = 350.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Finisher GAS")
	bool ExecuteFinisherAbility(EAshenPartyFinisherType FinisherType, AActor* TargetActor);
};
