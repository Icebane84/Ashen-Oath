// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenAnimNotifyState_SlashVFX.h"
#include "AshenVFXPoolSubsystem.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"

UAshenAnimNotifyState_SlashVFX::UAshenAnimNotifyState_SlashVFX()
{
	TrailVFXName = FName("VFX_OathbringerSlashTrail");
	SocketName = FName("FX_BladeTip");
}

void UAshenAnimNotifyState_SlashVFX::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (!MeshComp) return;

	UWorld* World = MeshComp->GetWorld();
	if (!World) return;

	FVector SocketLoc = MeshComp->GetSocketLocation(SocketName);
	FRotator SocketRot = MeshComp->GetSocketRotation(SocketName);

	if (UAshenVFXPoolSubsystem* VFXPool = World->GetSubsystem<UAshenVFXPoolSubsystem>())
	{
		VFXPool->SpawnPooledVFX(TrailVFXName, SocketLoc, SocketRot);
	}

	UE_LOG(LogTemp, Verbose, TEXT("UAshenAnimNotifyState_SlashVFX: NotifyBegin spawned trail '%s' at socket '%s'."),
		*TrailVFXName.ToString(), *SocketName.ToString());
}

void UAshenAnimNotifyState_SlashVFX::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	UE_LOG(LogTemp, Verbose, TEXT("UAshenAnimNotifyState_SlashVFX: NotifyEnd blade trail finished."));
}
