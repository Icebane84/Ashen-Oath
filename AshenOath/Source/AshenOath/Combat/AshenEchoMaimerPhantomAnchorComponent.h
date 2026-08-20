// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEchoMaimerPhantomAnchorComponent.generated.h"

/**
 * UAshenEchoMaimerPhantomAnchorComponent
 * Component managing ghost damage phantom hitbox lifetime and reality-anchor collapse for Echo-Maimer.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEchoMaimerPhantomAnchorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEchoMaimerPhantomAnchorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Echo Maimer")
	int32 ActivePhantomHitboxes = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Echo Maimer")
	void SpawnPhantomHitbox(FVector Location);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Echo Maimer")
	void CollapseAllPhantomTimelines();
};
