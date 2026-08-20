// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEliteCombatTrustAdapter.generated.h"

/**
 * UAshenEliteCombatTrustAdapter
 * Awards +0.08 companion trust when successfully parrying Shroud Knight warp strikes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEliteCombatTrustAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEliteCombatTrustAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float AwardEliteParryTrust(FName CompanionID);
};
