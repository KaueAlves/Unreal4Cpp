// Fill out your copyright notice in the Description page of Project Settings.


#include "EsferaFlamejante.h"
#include "Components/SphereComponent.h"
#include "Components/TextRenderComponent.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
AEsferaFlamejante::AEsferaFlamejante()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Cria uma instancia de USphereMeshComponent que ser� apontada por Esfera de colis�o.
	EsferaDeColisao = CreateDefaultSubobject<USphereComponent>(TEXT("Raiz"));

	//Define o raio de colis�o da Esfera
	EsferaDeColisao->InitSphereRadius(100.f);

	//Define o nome do perfil de colis�o
	EsferaDeColisao->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	//OverLap: Sobrepor

	//Indica que a EsferaDeColis�o ser� o Component raiz
	RootComponent = EsferaDeColisao;

	//Cria uma UStaticMeshComponent e armazena seu valor de memoria em EsferaVisivel
	EsferaVisivel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Esfera")); 

	//Cria um componente de particula e coloca o endere�o de memoria no ponteiro Particula de fogo
	ParticulaDeFogo = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fogo"));

	//Coloca este componente como filho de esfera Visivel
	ParticulaDeFogo->SetupAttachment(EsferaVisivel);

	//Coloca o Boolean que indica que o efeito deve come�ar assim que o jogo for iniciado
	ParticulaDeFogo->bAutoActivate = true;
	
	//Cria componente de texto de exibi��o 
	TextoDeExibicao = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Texto"));
	
	//Anexa o componente de Texto como filho de Esfera Visivel
	TextoDeExibicao->SetupAttachment(EsferaVisivel);
	
	//Indica que a posi��o do texto, em rela��o ao componente pai, ser� a do FVector
	TextoDeExibicao->SetRelativeLocation(FVector(0.f, 0.f, 110.f));
	
	//Alinha de forma centralizada o Texto
	TextoDeExibicao->SetHorizontalAlignment(EHTA_Center);
	
	//Indica tamanho 1 de escala em Y
	TextoDeExibicao->SetYScale(1.f);
	
	//Indica tamanho 1 de escala em X
	TextoDeExibicao->SetXScale(1.f);
	
	//Define o Texto que ser� exibido por padr�o
	TextoDeExibicao->SetText(FText::FromString("C++ na Unreal Udemy"));
	
	//Define a cor do texto que ser� exibido
	TextoDeExibicao->SetTextRenderColor(FColor::Red);
	
	//Define a se o texto estar� visiv�l
	TextoDeExibicao->SetVisibility(true);
	

	// HOOKS PARECIDOS COM WORDPRESS
	//Quando o evento overlap ocorrer a fun��o OnActorBeginOverlap � acionada
	//AddDynamic est� anexando a fun��o IniciouSobreposicao para que essa fun��o tbm seja executada ao ocorrer uma sobreposi��o.
	OnActorBeginOverlap.AddDynamic(this, &AEsferaFlamejante::IniciouSobreposicao);

	//AddDynamic est� anexando a fun��o TerminouSobreposicao para que essa fun��o tbm seja executada ao encerrar uma sobreposi��o.
	OnActorEndOverlap.AddDynamic(this,&AEsferaFlamejante::TerminouSobreposicao);

	//Adiciona Esfera Visivel como filho do Componente EsferaDeColis�o que � o Component Raiz
	EsferaVisivel->SetupAttachment(RootComponent);

	//ConstructorHelpers

	//Encontra o Objeto Shape_Sphere e cria o objeto na variavel Esfera.
	ConstructorHelpers::FObjectFinder<UStaticMesh>Esfera(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	//Encontra o Objeto M_Brick_Clay_New.M_Brick_Clay_New e cria o objeto na variavel MaterialEsfera.
	ConstructorHelpers::FObjectFinder<UMaterialInterface>MaterialEsfera(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));

	//Encontra o Objeto P_Fire.P_Fire e cria o objeto na variavel Fogo.
	ConstructorHelpers::FObjectFinder<UParticleSystem>Fogo(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));

	if (Esfera.Succeeded() && MaterialEsfera.Succeeded() && Fogo.Succeeded()) {
		//Define o StaticMesh como Esfera
		EsferaVisivel->SetStaticMesh(Esfera.Object);

		//Define o UMaterialInterface como Esfera
		EsferaVisivel->SetMaterial(0, MaterialEsfera.Object);

		//Define a posi��o relativa como FVector
		EsferaVisivel->SetRelativeLocation(FVector(0.f, 0.f, -60.f));

		//Define o UParticleSystem como Fogo
		ParticulaDeFogo->SetTemplate(Fogo.Object);
	}

}

// Called when the game starts or when spawned
void AEsferaFlamejante::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEsferaFlamejante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEsferaFlamejante::IniciouSobreposicao(AActor* OverlappedActor, AActor* OtherActor) {
	FString StringDeSaida;
	StringDeSaida = "Sobrepondo" + OtherActor->GetName() + " | ";
	TextoDeExibicao->SetText(FText::FromString(StringDeSaida));
}

void AEsferaFlamejante::TerminouSobreposicao(AActor* OverlappedActor, AActor* OtherActor) {
	TextoDeExibicao->SetText(FText::FromString(TEXT("Deixei de sobrepor")));
}