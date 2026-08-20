// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCampfireCompanionTrustAdapter.generated.h"

/**
 * UAshenCampfireCompanionTrustAdapter
 * Grants +0.10 trust during deep campfire rest conversations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireCompanionTrustAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCampfireCompanionTrustAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float AwardCampfireConversationTrust(FName CompanionID);
};
