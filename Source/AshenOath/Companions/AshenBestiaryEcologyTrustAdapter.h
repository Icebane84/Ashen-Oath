// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenBestiaryEcologyTrustAdapter.generated.h"

/**
 * UAshenBestiaryEcologyTrustAdapter
 * Awards specialized companion trust (+0.15) when successfully coordinating bestiary weakspot exploits.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBestiaryEcologyTrustAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBestiaryEcologyTrustAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float AwardEcologyFinisherTrust(EAshenPartyFinisherType FinisherType, FName CompanionID);
};
