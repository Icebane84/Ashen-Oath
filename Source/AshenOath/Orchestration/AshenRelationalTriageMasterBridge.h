// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalTriageTypes.h"
#include "AshenRelationalTriageMasterBridge.generated.h"

/**
 * UAshenRelationalTriageMasterBridge
 * Master domain bridge linking campfire relational triage outcomes with combat stance GAS abilities and companion AI trees.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelationalTriageMasterBridge : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRelationalTriageMasterBridge();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Orchestration")
	bool bRelationalBridgeActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	void BroadcastStanceCompiled(ECompiledRelationalStance Stance);
};
