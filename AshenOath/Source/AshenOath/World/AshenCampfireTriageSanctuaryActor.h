// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Companions/AshenRelationalTriageTypes.h"
#include "AshenCampfireTriageSanctuaryActor.generated.h"

/**
 * AAshenCampfireTriageSanctuaryActor
 * 3D world campfire actor triggering the multi-perspective relational triage sequence (The Chapter 4 Fortress garden scene).
 */
UCLASS()
class ASHENOATH_API AAshenCampfireTriageSanctuaryActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenCampfireTriageSanctuaryActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	bool bIsTriageSessionActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void InitiateRelationalTriage();
};
