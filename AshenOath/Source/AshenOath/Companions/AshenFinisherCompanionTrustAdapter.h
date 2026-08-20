// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenFinisherCompanionTrustAdapter.generated.h"

/**
 * UAshenFinisherCompanionTrustAdapter
 * Awards pairwise trust (+0.12) and unlocks advanced autonomous flank behaviors upon synchronized finisher execution.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherCompanionTrustAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherCompanionTrustAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float AwardFinisherTrust(EAshenPartyFinisherType FinisherType, FName CompanionID);
};
