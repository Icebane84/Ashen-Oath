// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryCompanionTrustAdapter.generated.h"

/**
 * UAshenMemoryCompanionTrustAdapter
 * Awards companion relational insights and pairwise trust when Kaelen successfully confronts and resolves shared traumatic memories.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryCompanionTrustAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryCompanionTrustAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float EvaluateMemoryTrustDelta(FName EchoID, bool bVictory, FName CompanionID);
};
